#!/bin/bash
#original source:
#https://https://github.com/INNOXSE/simple_shell 
set -e

#cd "$(dirname "$(readlink -f "$BASH_SOURCE")")/.."

{
	cat <<-'EOH'
	# This file lists the names of colaborators to the simple shell project repo.
	EOH
	echo
	git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
