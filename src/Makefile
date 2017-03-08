all:
	$(MAKE) -C queue/ all
	$(MAKE) -C heap/ all
	$(MAKE) -C list/ all
	ar rcs ../build/dslib.a heap/*.o queue/*.o list/*.o

clean:
	$(MAKE) -C queue/ clean
	$(MAKE) -C heap/ clean
	$(MAKE) -C list/ clean
	rm ../build/*
