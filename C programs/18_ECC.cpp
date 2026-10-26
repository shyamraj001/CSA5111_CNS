#include <stdio.h>

#define P 17
#define A 2

typedef struct {
    int x, y;
    int infinity;
} Point;

int mod(int x) {
    return (x % P + P) % P;
}

int inverse(int x) {
    int i;

    for (i = 1; i < P; i++) {
        if (mod(x * i) == 1)
            return i;
    }

    return -1;
}

Point add(Point p, Point q) {
    Point r;
    int slope, inv;

    if (p.infinity) return q;
    if (q.infinity) return p;

    if (p.x == q.x && mod(p.y + q.y) == 0) {
        r.infinity = 1;
        return r;
    }

    if (p.x == q.x && p.y == q.y) {
        inv = inverse(mod(2 * p.y));
        if (inv == -1) {
            r.infinity = 1;
            return r;
        }
        slope = mod((3 * p.x * p.x + A) * inv);
    } else {
        inv = inverse(mod(q.x - p.x));
        if (inv == -1) {
            r.infinity = 1;
            return r;
        }
        slope = mod((q.y - p.y) * inv);
    }

    r.x = mod(slope * slope - p.x - q.x);
    r.y = mod(slope * (p.x - r.x) - p.y);
    r.infinity = 0;

    return r;
}

Point multiply(int k, Point p) {
    Point result = {0, 0, 1};

    while (k > 0) {
        if (k & 1)
            result = add(result, p);

        p = add(p, p);
        k >>= 1;
    }

    return result;
}

int main() {
    Point G = {5, 1, 0};
    Point result;
    int privateKey;

    printf("Enter private key (1-19): ");
    scanf("%d", &privateKey);

    if (privateKey < 1 || privateKey > 19) {
        printf("Invalid private key\n");
        return 1;
    }

    result = multiply(privateKey, G);

    if (result.infinity)
        printf("Public key: Point at infinity\n");
    else
        printf("Public key: (%d, %d)\n",
               result.x, result.y);

    return 0;
}
