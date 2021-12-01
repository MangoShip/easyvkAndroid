#include <vector>
#include <iostream>
#include <easyvk.h>
#include <cassert>

const int size = 1;

int main(int argc, char* argv[]) {
	auto instance = easyvk::Instance(true);
	auto device = instance.devices().at(0);
	auto a = easyvk::Buffer(device, size);

	a.store(0, 0);

	std::vector<easyvk::Buffer> bufs = {a};
	const char* testFile = "kernel-test.spv";

	auto program = easyvk::Program(device, testFile, bufs);
	program.setWorkgroups(size);
	program.setWorkgroupSize(1);
	program.prepare();
	program.run();
	
	std::cout << "a[" << 0 << "]: " << a.load(0) << "\n";
	
	program.teardown();
	a.teardown();
	device.teardown();
	instance.teardown();
	return 0;
}
