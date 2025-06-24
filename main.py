from bot import BasicBot
import os
from dotenv import load_dotenv

load_dotenv()

api_key = os.getenv("API_KEY")
api_secret = os.getenv("API_SECRET")

bot = BasicBot(api_key, api_secret)

symbol = input("Symbol (BTCUSDT): ").upper()
side = input("Side (BUY/SELL): ").upper()
order_type = input("Order type (MARKET/LIMIT): ").upper()
quantity = float(input("Quantity: "))

price = None
if order_type == "LIMIT":
    price = input("Price: ")

bot.place_order(symbol, side, order_type, quantity, price)

