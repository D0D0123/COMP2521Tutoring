#!/bin/bash

stat * | grep -e 'File' -e 'Modify'


# The make utility examines time relationships and shall update those derived files (called targets) that have modified 
# times earlier than the modified times of the files (called prerequisites) from which they are derived.