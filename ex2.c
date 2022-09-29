
/* Địa chỉ cơ bản của watchdog */
#define WDT_BASE_ADDR 0x44E35000


/* Offsets */

/* WSPR */
#define WDT_EN_OFFSET 0x48
#define WDT_PING_OFFSET 0x30
#define WDT_STATUS_OFFSET 0x14

#define WDT_WCLR    0x24
#define WDT_WLDR    0x2C

/* taodc added */
#define WRITE_REG(ADDR, VALUE)      *((uint32_t*)(ADDR)) = VALUE
#define READ_REG(ADDR, MASK)        *((uint32_t*)(ADDR)) & (MASK)

/*
* bbb_wdt_enable sẽ có thực hiện enable watchdog
*/
void bbb_wdt_enable(void)
{
    uint32_t *wdt_en_res = (WDT_BASE_ADDR + WDT_EN_OFFSET);
    uint32_t *wdt_status_res = (WDT_BASE_ADDR + WDT_STATUS_OFFSET);
    uint32_t *wdt_control_pre = (WDT_BASE_ADDR + WDT_WCLR);
    uint32_t *wdt_reload = (WDT_BASE_ADDR + WDT_WLDR);


    /* disable watchdog */
    *wdt_en_res = 0xAAAA;

    /* set prescale value */
    wdt_control_pre[2] = 1;
    wdt_control_pre[3] = 1;

    /* enable prescale */
    *wdt_control_pre[5] = 1;

    /* load delay value*/

    /* load timer counter */
    /* default clock is 32KHZ so, 120s has value: 0x3A9800 */
    *wdt_status_res = 0;
    

    /* Enable Watchdog timer */
    *wdt_en_res = 0xBBBB;
}


/*
* bbb_wdt_ping sẽ thực hiện trigger(reload thanh ghi đếm ngược) watchdog
*/

void bbb_wdt_ping(void)

{
    uint32_t *wdt_ping_res = (WDT_BASE_ADDR + WDT_PING_OFFSET);

    /* Ping watchdog: write a differ value to trigger reload timer */
    *wdt_ping_res = *wdt_ping_res + 0x1;
}

int main(void)
{
    /* Kích hoạt watchdog */
    bbb_wdt_enable();

    /* Ping watchdog theo chu kì 2 phút */
    while (true) {

        bbb_wdt_ping();

        /* Sleep 2 minutes */
        sleep(120);
    };

    return 0;

}