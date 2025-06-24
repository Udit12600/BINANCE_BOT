import logging
logging.basicConfig(filename='bot.log', level=logging.INFO)
import os
from dotenv import load_dotenv
from binance.client import Client
import logging
class BasicBot:
    def __init__(self, api_key, api_secret, testnet=True):
        self.client = Client(api_key, api_secret)
        if testnet:
            self.client.FUTURES_URL = 'https://testnet.binancefuture.com/fapi'
            self.client.API_URL = 'https:/testnet.binancefuture.com/fapi'
        logging.info("Client initialized for Binance Futures Testnet")

    def place_order(self, symbol, side, order_type, quantity, price=None):
        try:
            if order_type == 'MARKET':
                order = self.client.futures_create_order(
                    symbol=symbol,
                    side=side,
                    type=order_type,
                    quantity=quantity
                )
            elif order_type == 'LIMIT':
                order = self.client.futures_create_order(
                    symbol=symbol,
                    side=side,
                    type=order_type,
                    timeInForce='GTC',
                    quantity=quantity,
                    price=price
                )
            else:
                raise ValueError("Unsupported order type.")
            print("✅ Order placed:", order)
            logging.info(f"Order successful: {order}")
        except Exception as e:
            print("❌ Error placing order:", e)
            logging.error(f"Order error: {e}")
