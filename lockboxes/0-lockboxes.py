#!/usr/bin/python3
"""method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.
    Args:
        boxes: List of list
    Returns:
        True or false
    """
    n = len(boxes)
    opened_boxes = [False] * n
    opened_boxes[0] = True      # boxes[0] is already unlocked
    keys = boxes[0]      # the key of the first box

    # check available keys
    while keys:
        current_key = keys.pop()    # retrieve a key from the stack
        # check if the box associated to this key is opened or not
        if current_key < n and not opened_boxes[current_key]:
            opened_boxes[current_key] = True    # mark the box as opened
            keys.extend(boxes[current_key])  # add all the keys to the stack

    return all(opened_boxes)
