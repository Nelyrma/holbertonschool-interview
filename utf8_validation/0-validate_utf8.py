#!/usr/bin/python3
"""validate utf-8 module
"""

def validUTF8(data):
    """
    determine if a given data set represents a valid UTF-8 encoding
    """
    # remaining bytes to check for the actual data
    remaining_bytes = 0

    for byte in data:
        header_bit = 1 << 7

        if remaining_bytes == 0:
            while header_bit & byte:
                remaining_bytes += 1
                header_bit = header_bit >> 1

            if remaining_bytes == 0:
                continue
            if remaining_bytes == 1 or remaining_bytes > 4:
                return False
        
        else:
            if (byte >> 6) != 0b10:
                return False
    
        remaining_bytes -= 1

    return remaining_bytes == 0
