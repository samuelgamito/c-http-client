# cmake --build build --clean-first
# cmake -B build -G Ninja
# cmake --build build
# ./build/c-http-client
# cmake -B build




cmake:
	rm -rf build
	cmake -B build
	cmake --build build --clean-first
