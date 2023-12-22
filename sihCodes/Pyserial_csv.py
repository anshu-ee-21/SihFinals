import serial
import csv
import os

# Replace 'COM3' with the appropriate serial port for your Arduino
ser = serial.Serial('COM5', 9600, timeout=1)

data_folder = 'data'
os.makedirs(data_folder,exist_ok=True)
# Open a CSV file for appending
csv_path = os.path.join(data_folder,'sensor_data.csv')
with open('sensor_data.csv', 'a', newline='') as csv_file:
    csv_writer = csv.writer(csv_file)

    # Uncomment the next line if you want to write the header only once
    # csv_writer.writerow(['Level', 'Rainfall', 'Inflow'])

    while True:
        # Read a line from serial
        line = ser.readline().decode('utf-8').strip()

        # Split the values
        values = line.split(',')

        # Write values to CSV
        csv_writer.writerow(values)

        # Print values to console (optional)
        print(values)