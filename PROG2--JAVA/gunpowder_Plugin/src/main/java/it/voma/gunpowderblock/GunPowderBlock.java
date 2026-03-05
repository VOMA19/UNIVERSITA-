package it.voma.gunpowderblock;

import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.Material;
import org.bukkit.NamespacedKey;
import org.bukkit.enchantments.Enchantment;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.BlockPlaceEvent;
import org.bukkit.inventory.ItemFlag;
import org.bukkit.inventory.ItemStack;
import org.bukkit.inventory.RecipeChoice;
import org.bukkit.inventory.ShapedRecipe;
import org.bukkit.inventory.ShapelessRecipe;
import org.bukkit.inventory.meta.ItemMeta;
import org.bukkit.plugin.java.JavaPlugin;

public class GunPowderBlock extends JavaPlugin implements Listener {

    private ItemStack customGunpowderBlock;

    @Override
    public void onEnable() {
        // 1. Creiamo il nostro oggetto personalizzato
        createCustomItem();

        // 2. Creiamo le ricette di andata e ritorno
        registerRecipes();

        // 3. Registriamo gli eventi (per impedire che venga piazzato a terra)
        getServer().getPluginManager().registerEvents(this, this);

        getLogger().info("GunpowderBlock abilitato con successo!");
    }

    private void createCustomItem() {
        // Usiamo la polvere di cemento nera come "falso" blocco di polvere da sparo
        customGunpowderBlock = new ItemStack(Material.BLACK_CONCRETE_POWDER);
        ItemMeta meta = customGunpowderBlock.getItemMeta();

        // Cambiamo nome e colore
        meta.setDisplayName(ChatColor.DARK_GRAY + "" + ChatColor.BOLD + "Blocco di Polvere da Sparo");

        // Aggiungiamo un incantesimo finto per farlo luccicare e nascondiamo la scritta dell'incantesimo
        meta.addEnchant(Enchantment.UNBREAKING, 1, true);
        meta.addItemFlags(ItemFlag.HIDE_ENCHANTS);

        customGunpowderBlock.setItemMeta(meta);
    }

    private void registerRecipes() {
        // Chiavi uniche per le ricette
        NamespacedKey craftKey = new NamespacedKey(this, "craft_gunpowder_block");
        NamespacedKey uncraftKey = new NamespacedKey(this, "uncraft_gunpowder_block");

        // Ricetta per COMPATTARE (9 Polveri -> 1 Blocco)
        ShapedRecipe craftRecipe = new ShapedRecipe(craftKey, customGunpowderBlock);
        craftRecipe.shape("GGG", "GGG", "GGG");
        craftRecipe.setIngredient('G', Material.GUNPOWDER);
        Bukkit.addRecipe(craftRecipe);

        // Ricetta per DECOMPATTARE (1 Blocco -> 9 Polveri)
        ItemStack nineGunpowder = new ItemStack(Material.GUNPOWDER, 9);
        ShapelessRecipe uncraftRecipe = new ShapelessRecipe(uncraftKey, nineGunpowder);
        // "ExactChoice" obbliga il giocatore a usare il nostro blocco esatto (col nome e l'incantesimo)
        uncraftRecipe.addIngredient(new RecipeChoice.ExactChoice(customGunpowderBlock));
        Bukkit.addRecipe(uncraftRecipe);
    }

    // Evento per impedire al giocatore di piazzare il blocco a terra
    @EventHandler
    public void onBlockPlace(BlockPlaceEvent event) {
        ItemStack itemInHand = event.getItemInHand();

        if (itemInHand.hasItemMeta() && itemInHand.getItemMeta().hasDisplayName()) {
            if (itemInHand.getItemMeta().getDisplayName().equals(ChatColor.DARK_GRAY + "" + ChatColor.BOLD + "Blocco di Polvere da Sparo")) {
                // Blocca l'azione
                event.setCancelled(true);
                // Manda un messaggio al giocatore
                event.getPlayer().sendMessage(ChatColor.RED + "Questo blocco serve solo per risparmiare spazio, non può essere piazzato!");
            }
        }
    }
}