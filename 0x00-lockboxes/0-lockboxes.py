#!/usr/bin/python3
# Algo to unlock boxes that may contain keys to other boxes


def canUnlockAll(boxes):
    """function to check if all boxes can be unlocked"""
    visited = [False for i in range(len(boxes))]
    visited[0] = True
    stack = [0]
    while len(stack):
        box = stack.pop(0)
        for i in boxes[box]:
            if isinstance(i, int)\
                    and i >= 0 and i < len(boxes) and not visited[i]:
                visited[i] = True
                stack.append(i)
    return all(visited)
