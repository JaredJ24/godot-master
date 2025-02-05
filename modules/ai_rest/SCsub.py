'''#!/usr/bin/env python
from misc.utility.scons_hints import *

Import("env")
Import("env_modules")

env_ai_rest = env_modules.Clone()

# Add all the C++ source files in this module
env_ai_rest.add_source_files(env.modules_sources, "*.cpp")'''