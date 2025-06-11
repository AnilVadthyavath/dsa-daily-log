
import os
import datetime
from pathlib import Path

LOG_FOLDER = Path(".")

# Get log files like 2025-06-11.md
log_files = sorted([f for f in LOG_FOLDER.glob("20*.md") if f.is_file()])
days_logged = len(log_files)
total_problems = 0
dates = []

for file in log_files:
    date_str = file.stem
    try:
        date_obj = datetime.datetime.strptime(date_str, "%Y-%m-%d").date()
        dates.append(date_obj)
        with open(file, "r", encoding="utf-8") as f:
            lines = f.readlines()
            total_problems += sum(1 for line in lines if line.strip().startswith("- [x]"))
    except:
        pass

# Calculate streaks
dates = sorted(set(dates))
today = datetime.date.today()
current_streak = 0
longest_streak = 0
streak = 0
prev = None

for date in dates:
    if prev and (date - prev).days == 1:
        streak += 1
    else:
        streak = 1
    longest_streak = max(longest_streak, streak)
    prev = date

    if date == today or (date == today - datetime.timedelta(days=1)):
        current_streak = streak

# Inject into README.md
README_FILE = "README.md"
START = "<!--STATS-START-->"
END = "<!--STATS-END-->"

with open(README_FILE, "r", encoding="utf-8") as f:
    content = f.read()

new_stats = f"""\
**DSA Practice Stats**

- 🔥 Total Problems Solved: {total_problems}  
- 📅 Days Logged: {days_logged}  
- 🔁 Current Streak: {current_streak} days  
- 🥇 Longest Streak: {longest_streak} days
"""

# Replace the section
updated = content.split(START)[0] + START + "\n\n" + new_stats + "\n" + END + content.split(END)[1]

with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(updated)
