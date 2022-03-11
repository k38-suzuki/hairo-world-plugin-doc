#!/bin/bash

rm -rf docs/*
mkdir ja/_static
sphinx-build -b html ja docs
touch docs/.nojekyll
