#include "if_can.h"


extern CAN_HandleTypeDef hcan;

void if_can_init(void) {
    HAL_CAN_Start(&hcan);
}

void if_can_send_telemetry(uint32_t id, const uint8_t* data, uint8_t len) {
    CAN_TxHeaderTypeDef tx_header = {0};
    uint32_t mailbox;

    tx_header.StdId = id;                 //! 11-bit standard ID
    tx_header.IDE   = CAN_ID_STD;         //! standard frame
    tx_header.RTR   = CAN_RTR_DATA;       //! data frame
    tx_header.DLC   = len;                //! caller ensures len <= 8
    tx_header.TransmitGlobalTime = DISABLE;

    HAL_CAN_AddTxMessage(&hcan, &tx_header, (uint8_t*)data, &mailbox);
}
