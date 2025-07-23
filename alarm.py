import datetime as dt
from os import system
from time import sleep
from pydub import AudioSegment
from pydub.playback import play

msg1 = input("Header text: ")
msg2 = input("Caption text: ")

sfx = input("Choose sound effect (1-5): ")

if int(sfx) > 5 or int(sfx) < 1:
    sfx = input("Invalid sound effect, please choose another: ")


def get_time_input(prompt, max_value):
    while True:
        value = input(prompt)
        if value.isdigit() and 0 <= int(value) <= max_value:
            return int(value)
        print(f"Invalid input, please enter a number between 0 and {max_value}.")


# Get user input for alarm time
hour = get_time_input("Hours (0-23): ", 23)
minute = get_time_input("Minutes (0-59): ", 59)
second = get_time_input("Seconds (0-59): ", 59)

print(f"Alarm set for {hour:02d}:{minute:02d}:{second:02d}")

# Wait until the current time matches the alarm time
while True:
    now = dt.datetime.now()
    if (now.hour, now.minute, now.second) == (hour, minute, second):
        break
    sleep(1)

# Play the alarm sound once
system(f'notify-send "{msg1}" "{msg2}"')
song = AudioSegment.from_mp3(f"src/sfx/{sfx}.mp3")
play(song)

print("Alarm finished!")
