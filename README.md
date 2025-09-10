<p>

# Aaron Money (aa746663)<br>

# EEL 5862<br>

# 09/07/2025<br>

# Application 1

## Thematic Application: Space Systems</p> 

<p>Q1. Vary Priorities: Change the print task’s priority to 2 (higher than blink’s 1). With such short tasks and delays, you may not notice a big difference, but in principle the print task would preempt the blink task if it were ready. Given both tasks spend most time sleeping, the effect is minimal. In later projects with CPU-bound tasks, priority will matter more. Does anything happen to the LED if you increase the delay within the print task? What if you increase the number of characters printed?</p><p>In the case of developing a satellite software that transmits telemetry data on time, modifying the delay of the when the telemtry data is transmitted does not noticeably affect the satellite's beacon blink pattern. This is because modifying the delay in the telemetry data transmission doesn't change the fact that it is still sleeping when it is not prompted to transmit.</p><p>Q2. Increase Load: Remove the vTaskDelay in the print task (making it a tight loop printing continuously). Be careful – this will flood the console. But it illustrates a point: if one task never yields, it can starve the other. In this case, the LED might stop blinking on schedule because the print task hogs the CPU. This is a starvation scenario, leading into Project 2. If you try this, reset it back after observing a few lines, to avoid crashing your serial output. Describe the behavior you observed.</p><p>When removing the delay for when the satellite telemetry data is transmitted, the satellite beacon blinking pattern would be disrupted. As time continues, the beacon blink delay gets progressively longer due to it being starved by the constant transmission of telemetry data because of the telemetry transmission (which still has a higher priority than the beacon pattern) is hogging all of the CPU.</p>
