import subprocess
import time

# Define the path to your Python script
script_path = "Pyserial_csv.py"

# Define the interval in seconds
interval = 5  # Adjust this to the desired interval

# Start the script
process = subprocess.Popen(['python', script_path])

try:
    while True:
        # Wait for the specified interval
        time.sleep(interval)

        # Terminate the running script
        process.terminate()

        # Wait for the process to finish (give it some time to clean up)
        process.wait()

        # Restart the script
        process = subprocess.Popen(['python', script_path])

except KeyboardInterrupt:
    # Handle KeyboardInterrupt (Ctrl+C) to stop the script gracefully
    print("Stopping the script...")
    process.terminate()
    process.wait()
    print("Script stopped.")

    import sys
    print("version : ", sys.version)
    print("sys.path :", sys.path)