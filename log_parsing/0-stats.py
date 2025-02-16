#!/usr/bin/env python3
"""Script that reads stdin line by line and computes metrics."""


import sys
import re
from collections import defaultdict

# Variable initialization
total_size = 0
status_counts = defaultdict(int)
valid_status_codes = {200, 301, 400, 401, 403, 404, 405, 500}
line_count = 0

def print_stats():
    """ Affiche les statistiques demandées """
    print(f"File size: {total_size}")
    for code in sorted(status_counts):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")

try:
    for line in sys.stdin:
        # Regular expression to extract data
        match = re.match(r'^(\S+) - \[(.*?)\] "GET /projects/260 HTTP/1.1" (\d{3}) (\d+)$', line)
        if match:
            status_code = int(match.group(3))
            file_size = int(match.group(4))

            # Statistics update
            total_size += file_size
            if status_code in valid_status_codes:
                status_counts[status_code] += 1
            
            line_count += 1

        # Display every 10 lines
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    sys.exit(0)
