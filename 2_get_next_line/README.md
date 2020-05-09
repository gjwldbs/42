# get_next_line

### :mag_right:Evaluated
+ score : 115 (100 mandatory + 15 bonus)
### :mag_right: Objective
- to code a function that returns a line ending with a newline, read from a file descriptor
- to learn a highly interesting new concept in C programming: `static variables`
### :mag_right: Codes
1. Mandatory Part
    - ***function description*** : returns a line read from a file descriptor, without the newline
    - ***compile option*** : gcc -Wall -Wextra -Werror `-D BUFFER_SIZE=32` get_next_line.c get_next_line_utils.c
    - since libft is not allowed, up to 5 functions can be added in gnl_utils.c
2. Bonus Part
    - ***requirement 1***: to succeed get_next_line with a single static variable.
    - ***requirement 2***: to be able to manage multiple file descriptors with get_next_line without losing the reading thread on each of the descriptors.