file(REMOVE_RECURSE
  "../bin/test/hello"
  "../bin/test/hello.pdb"
  "CMakeFiles/hello.dir/hello.cxx.o"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/hello.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
