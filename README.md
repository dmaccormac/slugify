# slugify - sanitize strings for filename or URL usage

## Overview

Slugify cleans up strings by performing the following transformations:

- Transform to lowercase
- Replace all spaces with '-' characters
- Remove all non alpha-numeric characters

## Installation

Download the `dist` directory and run the`slugify` binary or compile source using provided `cmake` file.

## Usage

### Example 1: Provide strings to slugify as arguments

`./slugify "First ?unclean string" "Second *unclean string"`

Output:

    first-unclean-string
    second-unclean-string

### Example 2: Using makedir.sh script

The idea here is to provide a text file with list of unclean directory names.
The script then reads each line of the file, slugifies it and creates a corresponding directory which is prefixed with a number.

`./makedir.sh test.txt`

Directories created:

    01-this-is-a-test
    02-and-another
    03-and-one-more
