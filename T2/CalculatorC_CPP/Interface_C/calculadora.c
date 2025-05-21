#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

static void on_button_clicked(GtkWidget *widget, gpointer entry) {
    const gchar *label = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar *current = gtk_entry_get_text(GTK_ENTRY(entry));

    if (strcmp(label, "C") == 0) {
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    } else if (strcmp(label, "Del") == 0) {
        int len = strlen(current);
        if (len > 0) {
            gchar *new_text = g_strndup(current, len - 1);
            gtk_entry_set_text(GTK_ENTRY(entry), new_text);
            g_free(new_text);
        }
    } else {
        gchar *new_text = g_strdup_printf("%s%s", current, label);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
        g_free(new_text);
    }
}

// Função de avaliação simples (suporta + - * / com ordem da esquerda para direita)
double evaluate_expression(const char *expr) {
    double result = 0;
    char op = 0;
    const char *p = expr;
    while (*p) {
        double num;
        char next_op = 0;
        if (sscanf(p, "%lf", &num) != 1)
            break;

        if (op == 0)
            result = num;
        else {
            switch (op) {
                case '+': result += num; break;
                case '-': result -= num; break;
                case '*': result *= num; break;
                case '/': result /= num; break;
            }
        }

        // Pula o número
        while (*p && (*p == '.' || (*p >= '0' && *p <= '9'))) p++;
        // Lê o próximo operador
        if (*p) {
            op = *p;
            p++;
        } else {
            break;
        }
    }
    return result;
}

static void on_equal_clicked(GtkWidget *widget, gpointer entry) {
    const gchar *expr = gtk_entry_get_text(GTK_ENTRY(entry));
    if (strlen(expr) == 0) return;

    double result = evaluate_expression(expr);
    gchar result_str[100];
    snprintf(result_str, sizeof(result_str), "%.2f", result);
    gtk_entry_set_text(GTK_ENTRY(entry), result_str);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora C GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 280, 350);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_container_set_border_width(GTK_CONTAINER(grid), 10);
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(entry), 1.0); // direita
    gtk_widget_set_hexpand(entry, TRUE);
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    const gchar *buttons[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", "Del", "=", "+"
    };

    for (int i = 0; i < 16; i++) {
        GtkWidget *button = gtk_button_new_with_label(buttons[i]);
        int col = i % 4;
        int row = i / 4 + 1;
        gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);

        if (strcmp(buttons[i], "=") == 0)
            g_signal_connect(button, "clicked", G_CALLBACK(on_equal_clicked), entry);
        else
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);
    }

    // Botão C (clear)
    GtkWidget *clear = gtk_button_new_with_label("C");
    gtk_grid_attach(GTK_GRID(grid), clear, 0, 5, 4, 1);
    g_signal_connect(clear, "clicked", G_CALLBACK(on_button_clicked), entry);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
