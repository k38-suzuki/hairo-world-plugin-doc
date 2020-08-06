#!/bin/bash

rm -rf docs/*
sphinx-build -b html ja docs
touch docs/.nojekyll
