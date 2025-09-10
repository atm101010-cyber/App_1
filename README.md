<p>
# Aaron Money (aa746663)<br>

# EEL 5862<br>

# 09/07/2025<br>

# Application 1</p> <p>Q1.Vary Priorities: Change the print task’s priority to 2 (higher than blink’s 1). With such short tasks and delays, you may not notice a big difference, but in principle the print task would preempt the blink task if it were ready. Given both tasks spend most time sleeping, the effect is minimal. In later projects with CPU-bound tasks, priority will matter more. Does anything happen to the LED if you increase the delay within the print task? What if you increase the number of characters printed?</p><p></p>
