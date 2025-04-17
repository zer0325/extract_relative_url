# About

This simple tool came about when I was looking at the `sample.js` file. I
noticed the pattern `"./xxxx"` which looks like a relative url. Looking at the
file there are several strings that have the same pattern. Since I wanted to
extract all those strings, I created this simple tool.

The gist of this tool is to get all the strings inside the quotes (") and then
perform some post-processing by getting only the strings with the following
pattern: `"./xxxx"` or `"/xxx`.


## Usage

1.  Compilation

        $ gcc xtrakt.c -o xtrakt

2.  Extracting the url

        $ ./xtrakt < sample.js > urls

## Note

To add more relative urls from other files to the `urls` text file:

`$ ./xtrkt < otherfiles >> urls`
