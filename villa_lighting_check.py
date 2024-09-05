#!/usr/bin/env python3

import time
import termcolor
from nano_llm import NanoLLM, ChatHistory
from nano_llm.utils import ArgParser
from nano_llm.plugins import VideoSource
from jetson_utils import cudaMemcpy, cudaToNumpy

# Parse arguments and set defaults
args = ArgParser(extras=ArgParser.Defaults + ['prompt', 'video_input']).parse_args()

# Define the prompts related to the scene and lighting conditions
prompts = [
    "What is in the view?",
    "Describe the lighting conditions. Is it well-lit or low light?"
]

# Set the model to use
if not args.model:
    args.model = "Efficient-Large-Model/VILA1.5-3b"

# Set video input source to the RGB camera (e.g., RealSense D435i)
if not args.video_input:
    args.video_input = "/dev/video4"

print(args)

# Load the vision/language model
model = NanoLLM.from_pretrained(
    args.model, 
    api=args.api,
    quantization=args.quantization, 
    max_context_len=args.max_context_len,
    vision_model=args.vision_model,
    vision_scaling=args.vision_scaling, 
)

assert model.has_vision

# Create the chat history
chat_history = ChatHistory(model)

# Open the video stream (from camera or file)
video_source = VideoSource(**vars(args), cuda_stream=0, return_copy=False)

# Process each frame from the video stream
while True:
    img = video_source.capture()
    
    if img is None:
        continue

    chat_history.append('user', image=img)
    time_begin = time.perf_counter()
    
    for prompt in prompts:
        chat_history.append('user', prompt, use_cache=True)
        embedding, _ = chat_history.embed_chat()
        
        print('>>', prompt)
        
        reply = model.generate(
            embedding,
            kv_cache=chat_history.kv_cache,
            max_new_tokens=args.max_new_tokens,
            min_new_tokens=args.min_new_tokens,
            do_sample=args.do_sample,
            repetition_penalty=args.repetition_penalty,
            temperature=args.temperature,
            top_p=args.top_p,
        )
        
        # Print the model's response
        for token in reply:
            termcolor.cprint(token, 'blue', end='\n\n' if reply.eos else '', flush=True)

        chat_history.append('bot', reply)
      
    time_elapsed = time.perf_counter() - time_begin
    print(f"time:  {time_elapsed*1000:.2f} ms  rate:  {1.0/time_elapsed:.2f} FPS")
    
    chat_history.reset()
    
    if video_source.eos:
        break

