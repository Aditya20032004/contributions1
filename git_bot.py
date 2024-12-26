import os
import subprocess
import google.generativeai as genai
import time
from datetime import datetime

GOOGLE_API_KEY = os.getenv('YOUR_GOOGLE_API_KEY') 

genai.configure(api_key=GOOGLE_API_KEY)
model = genai.GenerativeModel('gemini-pro')

def generate_python_code(prompt):
  """
  Generates Python code based on the given prompt.
  """
  response = model.generate_content(f"""
  Generate Python code that fulfills the following:

  {prompt}
  """)
  return response.text

def git_bot():
  """
  Automatically generates Python code, adds, commits, and pushes at 10:05 PM.
  """
  try:
    # Wait until 10:05 PM
    now = datetime.now()
    target_time = now.replace(hour=22, minute=5, second=0, microsecond=0)
    if now < target_time:
      time_to_wait = (target_time - now).total_seconds()
      time.sleep(time_to_wait)

    # Get user input for the code generation prompt
    prompt = input("Enter your prompt for Python code generation: ")

    # Generate Python code
    python_code = generate_python_code(prompt)

    # Create a temporary Python file
    with open("generated_code.py", "w") as f:
      f.write(python_code)

    # Stage the generated file
    subprocess.run(["git", "add", "generated_code.py"])

    # Generate commit message
    commit_message = model.generate_content(f"""
    Generate a concise commit message for the following changes:

    - Added 'generated_code.py' 
    """).text.strip()

    # Commit the changes
    subprocess.run(["git", "commit", "-m", commit_message])

    # Push the changes to remote repository
    subprocess.run(["git", "push"])

    print(f"Python code generated and pushed with message: {commit_message}")

  except Exception as e:
    print(f"An error occurred: {e}")

if __name__ == "__main__":
  git_bot()
