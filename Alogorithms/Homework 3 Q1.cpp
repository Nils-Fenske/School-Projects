void celebrityYesNo(int R[][], int rows, int columns, int n) {
	if (n == 0) return NULL;
	if (n == 1) return 1;
	int i = 0;
	int j = 1;
	while (j < columns) {
		if (R[i][j] == 0) j++;
		else if (R[i][j] == 1) { 
			i = j;
			j++;
		}
	}
	return "Person " + (i + 1) + " is the celebrity.";
}