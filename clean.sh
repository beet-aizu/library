#!/bin/bash
find . -name '*~' | xargs rm -v
find . -name 'a.out' | xargs rm -v
