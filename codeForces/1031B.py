import sys

def can_tile(w, h, a, b, x1, y1, x2, y2):
    rx1 = x1 % a
    rx2 = x2 % a
    ry1 = y1 % b
    ry2 = y2 % b

    vert_ok = (rx1 == rx2) and ((x1 != x2) or (ry1 == ry2))

    horiz_ok = (ry1 == ry2) and (y1 != y2)

    return vert_ok or horiz_ok

def main():
    input = sys.stdin.readline
    t = int(input().strip())
    out = []
    for _ in range(t):
        w, h, a, b = map(int, input().split())
        x1, y1, x2, y2 = map(int, input().split())
        out.append("Yes" if can_tile(w, h, a, b, x1, y1, x2, y2) else "No")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()

