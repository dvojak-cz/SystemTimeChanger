#!/bin/sh

set -e
BASEDIR=$(dirname $0)
chown 0:0 ${BASEDIR}/ChangeTime
chmod 4755 ${BASEDIR}/ChangeTime
