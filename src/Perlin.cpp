/*
 * Perlin.cpp
 *
 *  Created on: 22 Mar 2015
 *      Author: George
 */

#include "Perlin.h"

Perlin::Perlin() {
	p = new int[512];
	for (int x = 0; x < 512; x++) {
		p[x] = permutation[x%256];
	}
}

Perlin::~Perlin() {

}

double Perlin::fade(double t) {

	return t * t * t * (t * (t * 6 -15) + 10);
}

double Perlin::Perlin(double x, double y, double z) {

	int xi = (int)x & 255;
	int yi = (int)y & 255;
	int zi = (int)z & 255;
	double xf = x-(int)x;
	double yf = y-(int)y;
	double zf = z-(int)z;

	double u = fade(xf);
	double v = fade(yf);
	double w = fade(zf);

    int aaa, aba, aab, abb, baa, bba, bab, bbb;
    aaa = p[p[p[    xi ]+    yi ]+    zi ];
    aba = p[p[p[    xi ]+inc(yi)]+    zi ];
    aab = p[p[p[    xi ]+    yi ]+inc(zi)];
    abb = p[p[p[    xi ]+inc(yi)]+inc(zi)];
    baa = p[p[p[inc(xi)]+    yi ]+    zi ];
    bba = p[p[p[inc(xi)]+inc(yi)]+    zi ];
    bab = p[p[p[inc(xi)]+    yi ]+inc(zi)];
    bbb = p[p[p[inc(xi)]+inc(yi)]+inc(zi)];

    double x1, x2, y1, y2;
    x1 = lerp(grad(aaa, xf, yf, zf), grad(baa, xf-1, yf, zf), u);
    x2 = lerp(grad(aba, xf, yf-1, zf), grad(bba, xf-1, yf-1, zf), u);

    y1 = lerp(x1, x2, v);

    x1 = lerp(grad(aab, xf, yf, zf-1), grad(bab, xf-1, yf, zf-1), u);
    x2 = lerp(grad(abb, xf, yf-1, zf-1), grad(bbb, xf-1, yf-1, zf-1), u);

    y2 = lerp(x1, x2, v);

	return 0.0;
}

int Perlin::inc(int num) {
	num++;

	return num;
}

double Perlin::grad(int hash, double x, double y, double z) {
	int h = hash & 15;
	double u = h < 8 ? x : y;

	double v;

	if ( h < 4)
		v = y;
	else if (h == 12 || h == 14)
		v = x;
	else
		v=z;

	return ((h&1) == 0 ? u : -u) + ((h&2) == 0 ? v : -v);
}

double Perlin::lerp(double a, double b, double x) {

	return a + x * (b - a);
}
