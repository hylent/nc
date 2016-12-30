#!/bin/bash

git pull && rm -rf ext && zephir generate && git add --all . && git commit -m "Generate ext" && git push
