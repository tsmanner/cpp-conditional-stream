---
title: Profiling Results
classes: wide
---

|      System |           CPU | Memory |                         Disk | `ofstream`<br>`prof.txt` | `ofstream`<br>`/dev/null` | `ostringstream` | "blackhole"<br>`streambuf` | `ConditionalOStream`
|-------------|---------------|--------|------------------------------|--------------------------|---------------------------|-----------------|----------------------------|----------------------
| WSL2 Debian |      i7-8565U |   32GB |   Intel M.2 SSDPEKK- F512G8L |                 12.5022s |                  7.85131s |        7.88265s |                   6.95754s |            0.820528s
| WSL2 Debian | Ryzen 7 3800X |   32GB | Sabrent M.2 Rocket 4.0 500GB |                   7.994s |                  6.70774s |        5.84829s |                   3.81169s |            0.554443s
| NixOS 20.09 | Ryzen 7 1700  |   32GB |         PNY CS1311 240GB SSD |                 9.65714s |                  7.78467s |        7.22208s |                   5.08309s |            0.683112s
