#!/bin/bash
find . -name '*~' | xargs rm -v
find . -name 'a.out' | grep -v verify-helper | xargs rm -v
