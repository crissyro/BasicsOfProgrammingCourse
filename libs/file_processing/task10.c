#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float totalCost;
    int quantity;
} Product;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Order;

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }

    return file;
}

void generateProductsData(const char* filename) {
    FILE *file = openFile(filename, "wb");

    Product products[] = {
        {"Product1", 10.0, 100.0, 20},
        {"Product2", 15.0, 150.0, 30},
        {"Product3", 20.0, 200.0, 25},
    };

    fwrite(products, sizeof(Product), sizeof(products) / sizeof(Product), file);

    fclose(file);
}

void generateOrdersData(const char* filename) {
    FILE *file = openFile(filename, "wb");

    Order orders[] = {
        {"Product1", 5},
        {"Product2", 10},
    };

    fwrite(orders, sizeof(Order), sizeof(orders) / sizeof(Order), file);

    fclose(file);
}
  
void readProducts(const char* filename, Product** products, int* numProducts) {
    FILE *file = openFile(filename, "rb");

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *numProducts = fileSize / sizeof(Product);
    *products = (Product*)malloc(*numProducts * sizeof(Product));

    if (*products == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    fread(*products, sizeof(Product), *numProducts, file);

    fclose(file);
}

void readOrders(const char* filename, Order** orders, int* numOrders) {
    FILE *file = openFile(filename, "rb");

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *numOrders = fileSize / sizeof(Order);
    *orders = (Order*)malloc(*numOrders * sizeof(Order));
    if (*orders == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    fread(*orders, sizeof(Order), *numOrders, file);

    fclose(file);
}

void updateProducts(Product* products, int numProducts, Order* orders, int numOrders) {
    for (int i = 0; i < numOrders; i++) {
        for (int j = 0; j < numProducts; j++) {
            if (strcmp_(orders[i].name, products[j].name) == 0) {
                products[j].quantity -= orders[i].quantity;
                if (products[j].quantity <= 0) {
                    for (int k = j; k < numProducts - 1; k++) {
                        products[k] = products[k + 1];
                    }
                    numProducts--;
                }
                break;
            }
        }
    }
}

void writeProducts(const char* filename, Product* products, int numProducts) {
    FILE *file = openFile(filename, "wb");

    fwrite(products, sizeof(Product), numProducts, file);

    fclose(file);
}

void printProduct(Product product) {
    printf("Name: %s, Price: %.2f, Total Cost: %.2f, Quantity: %d\n", 
            product.name, product.price, product.totalCost, product.quantity);
}

void printOrder(Order order) {
    printf("Name: %s, Quantity: %d\n", order.name, order.quantity);
}

void printProductsFromFile(const char* filename) {
    Product* products;
    int numProducts;
    readProducts(filename, &products, &numProducts);

    printf("Products:\n");
    for (int i = 0; i < numProducts; i++) {
        printProduct(products[i]);
    }

    free(products);
}

void printOrdersFromFile(const char* filename) {
    Order* orders;
    int numOrders;
    readOrders(filename, &orders, &numOrders);

    printf("Orders:\n");
    for (int i = 0; i < numOrders; i++) {
        printOrder(orders[i]);
    }

    free(orders);
}

void getUpdatedInformationAboutProducts(const char* productsFilename, const char* ordersFilename) {
    Product* products;
    int numProducts;
    readProducts(productsFilename, &products, &numProducts);

    Order* orders;
    int numOrders;
    readOrders(ordersFilename, &orders, &numOrders);

    updateProducts(products, numProducts, orders, numOrders);

    printf("Updated products information:\n");
    for (int i = 0; i < numProducts; i++) {
        printProduct(products[i]);
    }

    writeProducts(productsFilename, products, numProducts);
    printf("Product information updated and saved.\n");

    free(products);
    free(orders);
}

int main() {
    const char* productsFilename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* ordersFilename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";

    generateProductsData(productsFilename);
    generateOrdersData(ordersFilename);

    printProductsFromFile(productsFilename);
    printOrdersFromFile(ordersFilename);

    getUpdatedInformationAboutProducts(productsFilename, ordersFilename);

    return 0;
}