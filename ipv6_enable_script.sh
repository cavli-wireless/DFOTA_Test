#!/bin/bash
MOBILEAP_CFG_XML="/data/mobileap_cfg.xml"
QCMAP_EXEC_NAME="QCMAP_ConnectionManager"
CAV_ATCMD_NAME="atcmd"
CAV_NW_SRV_NAME="cav_network_serviced"
QCMAP_INITD_SCRIPT="/etc/init.d/start_QCMAP_ConnectionManager_le"
PATCH_NAME="IPV6"
OUTMSG_ALREADY_UPDATE="$PATCH_NAME:ALREADY_UPDATE"
OUTMSG_NOTFOUND="$PATCH_NAME:NOT_FOUND"
OUTMSG_UPDATE_IPV6DNS="$PATCH_NAME:PATCHING"
OUTMSG_RESTART_SRV="$PATCH_NAME:SRV_RESTART"
OUTMSG_RESTART_SRV_COMPLETE="$PATCH_NAME:SRV_RESTARTED"

OUTMSG_ERR_RESTART_FAILED="$PATCH_NAME:SRV_RESTART_FAILED"

OUTMSG_END_OK="$PATCH_NAME:SUCCESS"
OUTMSG_END_ERROR="$PATCH_NAME:ERROR"

log_msg_to_screen()
{
    echo $1
}

restart_cavli_network_service()
{
    nw_srv_pid=$(pidof $CAV_NW_SRV_NAME)
    if [ "$nw_srv_pid" != "" ]; then
        killall -15 $CAV_NW_SRV_NAME
        for((i=0;i<3;i++));do
            sleep 2
            nw_srv_pid=$(pidof $CAV_NW_SRV_NAME)
            if [ $nw_srv_pid != "" ]; then
                break
            fi
        done
    else
        killall -15 $CAV_ATCMD_NAME
        for((i=0;i<3;i++));do
            sleep 2
            nw_srv_pid=$(pidof $CAV_ATCMD_NAME)
            if [ "$nw_srv_pid" != "" ]; then
                break;
            fi
        done
    fi

    if [ "$nw_srv_pid" != "" ]; then
        log_msg_to_screen $OUTMSG_RESTART_SRV_COMPLETE
        log_msg_to_screen $OUTMSG_END_OK
    else
        log_msg_to_screen $OUTMSG_ERR_RESTART_FAILED
        log_msg_to_screen $OUTMSG_END_ERROR
    fi
}

out=$(cat $MOBILEAP_CFG_XML | grep "<EnableDhcpv6Dns>" | tr -d '\t')
if [ "$out" == "" ]; then
    log_msg_to_screen $OUTMSG_NOTFOUND
    log_msg_to_screen $OUTMSG_END_ERROR
    exit 0
fi

if [ "$out" == "<EnableDhcpv6Dns>1</EnableDhcpv6Dns>" ]; then
    log_msg_to_screen $OUTMSG_ALREADY_UPDATE
    log_msg_to_screen $OUTMSG_END_ERROR
    exit 0
fi

if [ "$out" == "<EnableDhcpv6Dns>0</EnableDhcpv6Dns>" ]; then
    log_msg_to_screen $OUTMSG_UPDATE_IPV6DNS
    sed -i "s/<EnableDhcpv6Dns>0/<EnableDhcpv6Dns>1/" $MOBILEAP_CFG_XML
    log_msg_to_screen $OUTMSG_RESTART_SRV
    killall -15 $QCMAP_EXEC_NAME
    sleep 2
    $QCMAP_INITD_SCRIPT start
    restart_cavli_network_service
fi
