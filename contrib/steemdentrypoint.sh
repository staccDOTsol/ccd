#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start CreateCoind traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/CreateCoind
  cp /usr/local/bin/CreateCoin-sv-run.sh /etc/service/CreateCoind/run
  chmod +x /etc/service/CreateCoind/run
  runsv /etc/service/CreateCoind
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasCreateCoind.sh
fi
