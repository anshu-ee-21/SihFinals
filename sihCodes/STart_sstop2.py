import threading
import time
import subprocess


def run_script():
    # Replace 'path/to/your/script.py' with the actual path to your Python script
    script_path = '.\Pyserial_csv.py'

    while True:
        # Start the script
        process = subprocess.Popen(['python', script_path])

        # Wait for the specified interval
        time.sleep(60)  # Adjust this to the desired interval

        # Terminate the running script
        process.terminate()

        # Wait for the process to finish (give it some time to clean up)
        process.wait()


# Create a thread that runs the script
script_thread = threading.Thread(target=run_script)

# Start the thread
script_thread.start()

# Optionally, you can join the thread to wait for it to finish
# script_thread.join()