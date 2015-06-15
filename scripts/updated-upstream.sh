#!/bin/bash -xe

# Takes the main Contiki repository, extracts the coffee source directory and
# pushes the upstream state into the "upstream" branch of this cloned repository
#
# Execute from root of repository!

git clone https://github.com/contiki-os/contiki.git temp
cd temp
git subtree split -P core/cfs -b upstream
git remote add coffee ../.git
git push coffee upstream
rm -rf temp
