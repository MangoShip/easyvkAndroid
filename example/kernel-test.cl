__kernel void litmus_test(__global uint *a) {
	uint id = get_global_id(0);
	a[id] = 1234;
}
