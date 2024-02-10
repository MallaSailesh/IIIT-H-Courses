from main import *
def rule(cell_value: int, neighbours: "list[int]") -> int:
    if(neighbours[0] == int(1)):
        return int(1)
    return cell_value
