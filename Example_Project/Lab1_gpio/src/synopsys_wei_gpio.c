#include "synopsys_wei_gpio.h"

	HX_DRV_GPIO_E gpio_pin;                 /**< GPIO pin, assigned by user */
    uint8_t gpio_data;                      /**< GPIO data. Assigned by user when as output direction. Assigned by Himax driver when as input direction */
    HX_DRV_GPIO_DIRCTION_E gpio_direction;  /**< GPIO direction, assigned by user */

HAL_RETURN hal_gpio_init(hx_drv_gpio_config_t * hal_gpio, HX_DRV_GPIO_E hal_gpio_pin, HX_DRV_GPIO_DIRCTION_E hal_gpio_dir, GPIO_PIN_DATA hal_gpio_data)
{
  hal_gpio->gpio_data = hal_gpio_data;
  hal_gpio->gpio_direction = hal_gpio_dir;
  hal_gpio->gpio_pin = hal_gpio_pin;
  if(hx_drv_gpio_initial(hal_gpio) != HX_DRV_LIB_PASS)
    return HAL_ERROR;
  else
    return HAL_OK;
}

HAL_RETURN hal_gpio_set(hx_drv_gpio_config_t * hal_gpio, GPIO_PIN_DATA gpio_pin_data)
{
  hal_gpio->gpio_data = gpio_pin_data;
  if(hx_drv_gpio_set(hal_gpio) != HX_DRV_LIB_PASS)
    return HAL_ERROR;
  else
    return HAL_OK;
}

HAL_RETURN hal_gpio_get(hx_drv_gpio_config_t * hal_gpio, GPIO_PIN_DATA * gpio_pin_data)
{
  if(hx_drv_gpio_get(hal_gpio) != HX_DRV_LIB_PASS)
      return HAL_ERROR;
  else
  {
    *gpio_pin_data = hal_gpio->gpio_data;
    return HAL_OK;
  }
}