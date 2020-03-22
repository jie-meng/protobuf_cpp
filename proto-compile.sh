SRC_DIR=proto
DST_DIR=src/proto

protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/*.proto
