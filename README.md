mcut
====

Micro C++ Unit Tester

Examples
--------

```
TEST_CASE(strip_whitespaces_from_both_sides, {
	CHECK(strip("  \r\n\ttest example    \r\n") == "test example");
});
```

```
TEST_CASE(duffs_device, {
  const char *from = "save a few end-of-loop checks";
  const char *src = from;

  char dst[30];
  char *to = dst;
  size_t count = 30;
  

	size_t n = (count + 7) / 8;
	switch (count % 8) {
	case 0: do { *to++ = *from++;
	case 7:      *to++ = *from++;
	case 6:      *to++ = *from++;
	case 5:      *to++ = *from++;
	case 4:      *to++ = *from++;
	case 3:      *to++ = *from++;
	case 2:      *to++ = *from++;
	case 1:      *to++ = *from++;
	        } while (--n > 0);
	}

  CHECK(strcmp(src, dst) == 0);
});
```
