// Formula for prefix xors 0 ^ 1 ^ .... ^ k:
int xorUpToK(int k) {
	switch (k % 4) {
		case 0: return k;
		case 1: return 1;
		case 2: return k + 1;
		case 3: return 0;
	}
}