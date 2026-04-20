```
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_get_next_line                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: statooin <statooin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:54:43 by statooin          #+#    #+#              #
#    Updated: 2020/11/09 20:18:35 by statooin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```

# Efficient Buffer & I/O Management: get_next_line (2021)

[⚠️STATUS: ARCHIVAL / HISTORICAL REFERENCE]

## 📜 Overview
This repository contains an implementation of a function that reads a line from a file descriptor, returning the text ending with a newline. Developed in 2021 at École 42, this project focuses on efficient buffer management, the use of static variables for state persistence, and meticulous memory handling in C.

Maintaining this archive demonstrates my fundamental ability to handle low-level I/O operations and manage persistent state across function calls—core skills for any systems-level engineering.

## The Engineering Foundation (Why this matters for SRE)
At its core, GNL is a lesson in how to process data streams efficiently. For a Senior SRE, these principles are directly applicable to infrastructure observability:

* **Memory Safety & Leak Prevention:** In a long-running process like a monitoring agent, a tiny memory leak in a read loop can lead to an OOM (Out Of Memory) event. GNL requires perfect management of `malloc` and `free` across multiple calls.
* **State Persistence (Static Variables):** Using `static` variables to remember the "leftover" data from a previous read is a precursor to understanding stateful stream processing and buffering in distributed systems.
* **I/O Efficiency:** Learning to read data in specific buffer sizes (`BUFFER_SIZE`) and parsing it correctly without over-reading or missing data is key to building high-performance log shippers and parsers.

## Technical Deep-Dive
The implementation solves the problem of reading from a stream when you don't know the line length in advance:

* **Dynamic Buffering:** Reading from a File Descriptor into a temporary buffer and appending it to a "remainder" string until a `\n` is found.
* **Multi-FD Support (Bonus):** My implementation supports reading from multiple file descriptors simultaneously without cross-contamination. This mimics how a web server manages separate state buffers for multiple concurrent client connections.
* **Edge Case Handling:** Robust logic to handle EOF (End Of File), empty files, standard input (stdin), and varying `BUFFER_SIZE` values (from 1 to 1,000,000+).

## Project Contents
* `get_next_line.c`: The primary logic for reading and line extraction.
* `get_next_line_utils.c`: Helper functions for string manipulation and memory allocation.
* `get_next_line_bonus.c`: Extended implementation supporting concurrent reading from multiple file descriptors.
* `get_next_line.h`: Header file defining prototypes and the `BUFFER_SIZE` macro.

---
*This archive is part of my professional evolution, highlighting a deep-dive into I/O streams and state management that informs my approach to building resilient data pipelines and observability tools today.*
