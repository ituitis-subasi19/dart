#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int point_value(int segment, char ring) {
	int value;
	switch (ring) {
		case 'S':
			value = segment;
			break;
		case 'D':
			value = 2 * segment;
			break;
		case 'T':
			value = 3 * segment;
			break;
		case 'O':
			value = 25;
			break;
		case 'I':
			value = 50;
			break;
	}
	return value;
}

int remaining_points (int current_point, int segment, char ring) {
	int points = current_point;
	int value = point_value(segment, ring);
	if (current_point - value == 0) {
		if (ring == 'D') {
			points = 0;
		}
	} else if (current_point - value == 1 || current_point < value);
	else {
		points = current_point - value;
	}
	return points;
}

int main() {
	int target, segment, points;
	char ring;
	bool start = false;
	
	printf("Target: ");
	scanf("%d", &target);
	points = target;
	
	while (points > 0) {
		printf("Throw: ");
		scanf("%d %c", &segment, &ring);
		if (ring != 'D' && !start) {
			points = target;
		} else {
			points = remaining_points(points, segment, ring);
			start = true;
		}
		printf("Points: %d\n", points);
	}
	return 0;
}
