# this will generate a table-of-contents file for the given directory it's run in
# I have it added to my $PATH so that I can run it arbitrarily for testing

# Generally, the table of contents work by assigning a symbol to a byte offset
# each asset is 10 bytes apart and is given a size
# NAME=(START,STOP)
# testbmp=(500,3694)

byte=100

for filename in ./*; do
    # get filesize
    size=`wc -c < $filename`
    echo "`basename ${filename//.}`=($byte,$(($byte + size)))"
    # create the offset of size + 10 (10 byte buffer)
    byte=$(($byte + size + 10))
done
