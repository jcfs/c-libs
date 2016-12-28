all:
	$(MAKE) -C queue/ all
	$(MAKE) -C heap/ all
	ar rcs ../build/dslib.a heap/*.o queue/*.o

clean:
	$(MAKE) -C queue/ clean
	$(MAKE) -C heap/ clean
	rm ../build/*
