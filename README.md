# Smart Canteen Billing System

## Problem Statement

Develop a menu-driven billing system for a college canteen that allows customers to select food items, enter quantities, and generate a final itemized bill. The system also provides options to view the current order, remove items, and automatically apply a discount when the bill exceeds a specified amount.

## Team Details

**Team Number:** ____N______  
**Batch:** 59 

### Team Members
1. SARANYA 
2. UTPAL

---

## Objective

The objective of this project is to develop a simple and user-friendly canteen billing system using C programming. The system automates the process of selecting food items, calculating item-wise costs, applying discounts, and generating the final bill.

## Features

- Displays a menu of 8 food items with prices.
- Allows customers to order multiple food items.
- Accepts the quantity of each selected item.
- Allows customers to view their current order.
- Allows removal of an item from the order.
- Calculates item-wise cost automatically.
- Calculates the subtotal of the complete order.
- Applies a 10% discount when the subtotal is above Rs. 500.
- Generates an itemized final bill.
- Handles invalid item codes and quantities.
- Supports billing for multiple customers without restarting the program.

---

## C Programming Concepts Used

The project uses the following C programming concepts:

- Variables and data types
- Operators
- Conditional statements (`if`, `else`)
- Loops (`for`, `do-while`)
- Arrays
- Strings
- Functions
- Structures
- `switch-case`

---

## Algorithm

1. Start the program.
2. Create a `FoodItem` structure containing item code, item name, price, and quantity.
3. Store 8 food items in an array of structures.
4. Initialize the quantity of all food items to 0.
5. Display the canteen menu.
6. Display the following options:
   - Add Item
   - View Current Order
   - Remove Item
   - Generate Bill
7. Accept the user's choice.
8. If **Add Item** is selected:
   - Accept the item code.
   - Validate the item code.
   - Accept and validate the quantity.
   - Add the quantity to the selected item.
9. If **View Current Order** is selected:
   - Display all ordered items.
   - Calculate each item's cost using `Price × Quantity`.
   - Display the current total.
10. If **Remove Item** is selected:
    - Accept and validate the item code.
    - Check whether the item exists in the order.
    - Set its quantity to 0.
11. If **Generate Bill** is selected:
    - Calculate the subtotal.
    - If subtotal > Rs. 500, calculate a 10% discount.
    - Otherwise, set the discount to 0.
    - Calculate `Final Amount = Subtotal - Discount`.
    - Display the itemized final bill.
12. Ask whether another customer needs to be served.
13. If yes, reset all quantities to 0 and start a new order.
14. If no, close the program.
15. End.

---

## Menu

| Code | Item | Price |
|---|---|---:|
| 1 | Burger | Rs. 80 |
| 2 | Pizza | Rs. 120 |
| 3 | Sandwich | Rs. 60 |
| 4 | French Fries | Rs. 70 |
| 5 | Maggi | Rs. 50 |
| 6 | Momos | Rs. 80 |
| 7 | Cold Coffee | Rs. 90 |
| 8 | Soft Drink | Rs. 40 |

---

## Discount Rule

A **10% discount** is applied when the subtotal is greater than **Rs. 500**.

Example:

Subtotal = Rs. 520  
Discount = Rs. 52  
Final Amount = Rs. 468

---

## How to Compile and Run

### Compile

```bash
gcc canteen_billing.c -o canteen
```

### Run

```bash
./canteen
```

---

## Sample Test Cases

### Test Case 1 — Normal Order

**Input:**
- Pizza × 2
- Cold Coffee × 1

**Expected Result:**

Subtotal = Rs. 330  
Discount = Rs. 0  
Final Amount = Rs. 330

---

### Test Case 2 — Discount Applied

**Input:**
- Pizza × 3
- Burger × 2

**Calculation:**

Pizza = 3 × 120 = Rs. 360  
Burger = 2 × 80 = Rs. 160  

Subtotal = Rs. 520  
Discount (10%) = Rs. 52  
Final Amount = Rs. 468

---

### Test Case 3 — Invalid Item Code

**Input:**

Item Code = 15

**Expected Output:**

`Invalid item code!`

---

### Test Case 4 — Invalid Quantity

**Input:**

Quantity = -2

**Expected Output:**

`Invalid quantity!`

---

### Test Case 5 — Remove Item

Add Pizza to the order and then select the Remove Item option.

**Expected Result:**

Pizza is removed from the current order.

---

## Flowchart

The project flowchart illustrates the complete process from menu initialization and item selection to bill generation, discount calculation, and handling multiple customers.

Add the provided `flowchart.png` file to this section of the GitHub repository.

---

## Expected Output

The system generates an itemized bill containing:

- Item name
- Quantity
- Price
- Item-wise total
- Subtotal
- Discount
- Final payable amount

---

## Conclusion

The Smart Canteen Billing System provides a simple way to automate the billing process of a college canteen. The project demonstrates the practical use of fundamental C programming concepts such as structures, arrays, functions, loops, conditional statements, and switch-case while providing a useful real-world application.
