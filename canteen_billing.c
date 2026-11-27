#include <stdio.h>

struct FoodItem
{
    int code;
    char name[30];
    float price;
    int quantity;
};

void displayMenu(struct FoodItem menu[], int size)
{
    int i;

    printf("\n========================================\n");
    printf("          SMART COLLEGE CANTEEN\n");
    printf("========================================\n");

    printf("%-6s %-20s %s\n", "Code", "Item", "Price");
    printf("----------------------------------------\n");

    for (i = 0; i < size; i++)
    {
        printf("%-6d %-20s Rs. %.2f\n",
               menu[i].code,
               menu[i].name,
               menu[i].price);
    }

    printf("----------------------------------------\n");
}

void addItem(struct FoodItem menu[], int size)
{
    int code, qty;

    printf("\nEnter item code: ");
    scanf("%d", &code);

    if (code < 1 || code > size)
    {
        printf("Invalid item code!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (qty <= 0)
    {
        printf("Invalid quantity!\n");
        return;
    }

    menu[code - 1].quantity += qty;

    printf("%d x %s added to your order!\n",
           qty, menu[code - 1].name);
}

void viewOrder(struct FoodItem menu[], int size)
{
    int i;
    float total;
    int orderEmpty = 1;

    total = 0;

    printf("\n========== CURRENT ORDER ==========\n");
    printf("%-20s %-8s %-10s\n", "Item", "Qty", "Cost");
    printf("-----------------------------------\n");

    for (i = 0; i < size; i++)
    {
        if (menu[i].quantity > 0)
        {
            float cost;

            cost = menu[i].price * menu[i].quantity;

            printf("%-20s %-8d Rs. %.2f\n",
                   menu[i].name,
                   menu[i].quantity,
                   cost);

            total = total + cost;
            orderEmpty = 0;
        }
    }

    if (orderEmpty == 1)
    {
        printf("No items added yet!\n");
    }
    else
    {
        printf("-----------------------------------\n");
        printf("Current Total: Rs. %.2f\n", total);
    }
}

void removeItem(struct FoodItem menu[], int size)
{
    int code;

    printf("\nEnter item code to remove: ");
    scanf("%d", &code);

    if (code < 1 || code > size)
    {
        printf("Invalid item code!\n");
        return;
    }

    if (menu[code - 1].quantity == 0)
    {
        printf("%s is not in your order!\n",
               menu[code - 1].name);
        return;
    }

    menu[code - 1].quantity = 0;

    printf("%s removed from your order!\n",
           menu[code - 1].name);
}

void generateBill(struct FoodItem menu[], int size)
{
    int i;
    int orderEmpty = 1;
    float cost, subtotal = 0;
    float discount = 0;
    float finalAmount;

    printf("\n===============================================\n");
    printf("                  FINAL BILL\n");
    printf("===============================================\n");
    printf("%-18s %-6s %-9s %-10s\n",
           "Item", "Qty", "Price", "Total");
    printf("-----------------------------------------------\n");

    for (i = 0; i < size; i++)
    {
        if (menu[i].quantity > 0)
        {
            cost = menu[i].price * menu[i].quantity;

            printf("%-18s %-6d %-9.2f %.2f\n",
                   menu[i].name,
                   menu[i].quantity,
                   menu[i].price,
                   cost);

            subtotal = subtotal + cost;
            orderEmpty = 0;
        }
    }

    if (orderEmpty == 1)
    {
        printf("No items ordered!\n");
        printf("-----------------------------------------------\n");
        return;
    }

    /* Apply 10% discount if subtotal is above Rs. 500 */
    if (subtotal > 500)
    {
        discount = subtotal * 0.10;
    }

    finalAmount = subtotal - discount;

    printf("-----------------------------------------------\n");
    printf("Subtotal:                         Rs. %.2f\n", subtotal);
    printf("Discount:                         Rs. %.2f\n", discount);
    printf("-----------------------------------------------\n");
    printf("FINAL AMOUNT:                     Rs. %.2f\n", finalAmount);
    printf("===============================================\n");
    printf("              Thank You! :)\n");
    printf("===============================================\n");
}

int main()
{
    struct FoodItem menu[8] =
    {
        {1, "Burger",       80,  0},
        {2, "Pizza",        120, 0},
        {3, "Sandwich",     60,  0},
        {4, "French Fries", 70,  0},
        {5, "Maggi",        50,  0},
        {6, "Momos",        80,  0},
        {7, "Cold Coffee",  90,  0},
        {8, "Soft Drink",   40,  0}
    };

int choice;
char again;
int i;
do

{
    /* Reset order for a new customer */
    for (i = 0; i < 8; i++)
    {
        menu[i].quantity = 0;
    }

    displayMenu(menu, 8);

    do
    {
        printf("\n========= OPTIONS =========\n");
        printf("1. Add Item\n");
        printf("2. View Current Order\n");
        printf("3. Remove Item\n");
        printf("4. Generate Bill\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addItem(menu, 8);
                break;

            case 2:
                viewOrder(menu, 8);
                break;

            case 3:
                removeItem(menu, 8);
                break;

            case 4:
                generateBill(menu, 8);
                break;

            default:
                printf("Invalid choice! Please enter 1 to 4.\n");
        }

    } while (choice != 4);

    printf("\nServe another customer? (Y/N): ");
    scanf(" %c", &again);

} while (again == 'Y' || again == 'y');

printf("\nCanteen billing system closed.\n");

return 0;
}

